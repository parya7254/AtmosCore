#pragma once

#include <stdbool.h>
#include "data.h"

void espnow_init(void);
bool espnow_has_new_data(void);

OutdoorData get_data_espnow(void);