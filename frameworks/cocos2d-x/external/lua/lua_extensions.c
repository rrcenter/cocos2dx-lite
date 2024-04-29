
#include "lua_extensions.h"

// extern int luaopen_xxtea(lua_State *L);
// extern int luaopen_md5(lua_State *L);

#include "crypto/CCCrypto.h"
#if __cplusplus
extern "C" {
#endif

// cjson
#include "cjson/lua_cjson.h"

//// zlib
//#include "zlib/lua_zlib.h"

// lpack
extern int luaopen_pack(lua_State *L);

// socket
#include "luasocket/luasocket.h"
#include "luasocket/mime.h"
#include "luasocket/luasocket_scripts.h"

// lsocket 1.4.1
extern int luaopen_lsocket(lua_State *L);

// filesystem
#include "lfs/lfs.h"

#if CC_SQLITE_ENABLED > 0
// lsqlite3
#include "lsqlite3/lsqlite3.h"
#endif


    extern int luaopen_lpeg(lua_State *L);
    extern int luaopen_protobuf_c(lua_State *L);
    extern int luaopen_bit(lua_State *L);
    
    extern int luaopen_sproto_core(lua_State *L);


static luaL_Reg luax_exts[] = {
    { "cjson", luaopen_cjson_safe},
//    {"zlib", luaopen_zlib},
    { "pack", luaopen_pack},
    { "socket.core", luaopen_socket_core},
    { "mime.core", luaopen_mime_core},
    { "lfs", luaopen_lfs},
    { "lsocket", luaopen_lsocket},
    { "xxtea", luaopen_xxtea },
    { "md5", luaopen_md5 },
    { "lpeg", luaopen_lpeg },
    { "protobuf.c", luaopen_protobuf_c },
    { "bit", luaopen_bit},
    { "sproto.core", luaopen_sproto_core },

#if CC_SQLITE_ENABLED > 0
    {"lsqlite3", luaopen_lsqlite3},
#endif

    {NULL, NULL}
};

void luaopen_lua_extensions(lua_State *L)
{
    // load extensions
    luaL_Reg* lib = luax_exts;
    lua_getglobal(L, "package");
    lua_getfield(L, -1, "preload");
    for (; lib->func; lib++)
    {
        lua_pushcfunction(L, lib->func);
        lua_setfield(L, -2, lib->name);
    }
    lua_pop(L, 2);

    // load extensions script
    luaopen_luasocket_scripts(L);
}

#if __cplusplus
} // extern "C"
#endif
