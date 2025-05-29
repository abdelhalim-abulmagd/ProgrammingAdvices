#include "clsUser.h"

#include "Global.h"


static clsUser User = clsUser("");

clsUser *Global::CurrentUser = &User;