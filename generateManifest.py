#!/usr/bin/env python
#coding=utf-8

import os
import sys
import json
import hashlib
import semver
import collections

currdir = os.path.abspath(os.path.dirname(__file__))
assetsDir = {
    # 需要进行热跟的文件夹
    "searchDir" : ["src", "res"],
    # 需要忽略的文件夹
    "ignorDir" : [],
    # "ignorDir" : ["cocos", "framework", ".svn"],
    # 需要忽略的文件
    "ignorFile":[".DS_Store"],
}

versionConfigFile   = "res/config/version_info.json"  #版本信息的配置文件路径
versionManifestPath = "res/version/version.manifest"    #由此脚本生成的version.manifest文件路径
projectManifestPath = "res/version/project.manifest"    #由此脚本生成的project.manifest文件路径

def scan(*dirs, **kwargs):
  files = []
  extensions = kwargs['extensions'] if kwargs.has_key('extensions') else None
  excludes = kwargs['excludes'] if kwargs.has_key('excludes') else []
  for top in dirs:
    for root, dirnames, filenames in os.walk(top):
      dirnames = [i for i in dirnames if i in excludes]
      for f in filenames:
        if f in excludes:
          continue
        ext = os.path.splitext(f)[1].lower()
        if extensions is None or ext in extensions:
          files.append(os.path.join(root, f))
  return files


def CalcMD5(filepath):
    """generate a md5 code by a file path"""
    with open(filepath,'rb') as f:
        md5obj = hashlib.md5()
        md5obj.update(f.read())
        return md5obj.hexdigest()

def GetVersionInfo():
    if not os.path.exists(versionConfigFile):
        with open(versionConfigFile, 'w') as f:
            data = {
                'packageUrl':'http://package_url',
                'remoteManifestUrl':'http://path/to/project.manifest',
                'remoteVersionUrl':'http://path/to/version.manifest',
                'engineVersion':'3.0',
                'version':'1.0.0',
            }
            f.write(json.dumps(data, indent=4, sort_keys=True))
    '''get version config data'''
    configFile = open(versionConfigFile,"r")
    json_data = json.load(configFile)

    configFile.close()
    json_data["version"] = semver.bump_patch(json_data["version"])
    return json_data

def GenerateVersionManifestFile():
    versionInfo = GetVersionInfo()
    json_str = json.dumps(versionInfo, indent = 2)
    with open(versionManifestPath, 'w') as f:
        f.write(json_str)

def GenerateProjectManifestFile():
    extensions = ['.ExportJson', '.plist', '.json', '.animation', '.fnt', '.md', '.xml', '.tmx', '.lua', '.png']
    extensions = None
    fileList = scan('src', 'res', extensions=extensions, excludes=['.DS_Store', versionConfigFile, versionManifestPath, projectManifestPath])
    fileList = sorted(fileList)

    project_str = {}
    project_str.update(GetVersionInfo())
    dataDic = {}
    for f in fileList:
        dataDic[f] = {"md5" : CalcMD5(f)}
        print(f)

    print('\n'+str(len(fileList))+' files')

    project_str.update({"assets":dataDic})
    json_str = json.dumps(project_str, sort_keys = True, indent = 2)

    with open(projectManifestPath, 'w') as f:
        f.write(json_str)

def mkdir(path):
    if not os.path.exists(path):
        os.makedirs(path)

if __name__ == "__main__":
    os.chdir(currdir)
    mkdir(os.path.join(currdir, 'res/config'))
    mkdir(os.path.join(currdir, 'res/version'))
    GenerateProjectManifestFile()
    GenerateVersionManifestFile()

    versionInfo = GetVersionInfo()
    print('update %s,%s to %s version' %(versionManifestPath, projectManifestPath, versionInfo['version']))
