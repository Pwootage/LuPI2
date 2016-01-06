#include "luares.h"
#include "lupi.h"
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <stdlib.h>

void run_init() {
  lua_State *L;
  L = luaL_newstate();

  luaL_openlibs   (L);
  setup_modules   (L);
  luanative_start (L);
  termutils_start (L);

  int status = luaL_loadstring(L, lua_init);
  if (status) {
    fprintf(stderr, "Couldn't load init: %s\n", lua_tostring(L, -1));
    exit(1);
  }
  lua_call(L, 0, 0);
  lua_close(L);
}