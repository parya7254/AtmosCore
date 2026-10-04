#include "espnow.h"
#include <string.h>

#include "esp_now.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_netif.h"

OutdoorData g_outdoorData;

static void receiveCallback(const esp_now_recv_info_t *info, const uint8_t *data, int len){
    if(len != sizeof(OutdoorData)){
        return;
    }

    memcpy(&g_outdoorData, data, sizeof(OutdoorData));

}

void espnow_init(void){
    esp_netif_init();
    esp_event_loop_create_default();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    
    esp_wifi_init(&cfg);
    esp_wifi_set_mode(WIFI_MODE_STA);

    esp_wifi_start();
    esp_now_init();

    esp_now_register_recv_cb(receiveCallback);


}

bool espnow_has_new_data(void){
    return true;
}

OutdoorData espnow_get_data(void){
    return latestData;
}