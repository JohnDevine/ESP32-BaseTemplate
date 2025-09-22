/**
 * @file main.c
 * @brief Main application entry point
 * @version 0.2
 * @date 2025-09-17
 * @author john.h.devine@gmail.com
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "version.h"
#include "SystemMetrics.h"

// =============================
// Function Prototypes
// =============================
static void test_system_metrics(void);
static void display_startup_info(void);

// =============================
// Main Application
// =============================

void app_main() {
    // Start your application here
    printf("Gidday Mate\n");
    
    // Display startup information
    display_startup_info();
    
    // Initialize system metrics library
    ESP_LOGI("app_main", "Initializing System Metrics Library...");
    if (!system_metrics_init()) {
        ESP_LOGE("app_main", "Failed to initialize System Metrics Library");
        return;
    }
    
    // Test all system metrics
    test_system_metrics();
    
    ESP_LOGI("app_main", "System metrics test completed");
}

// =============================
// Helper Functions
// =============================

static void display_startup_info(void)
{
    ESP_LOGI("app_init", "=== ESP32 Weather Station - System Information ===");
    ESP_LOGI("app_init", "Project name:     %s", PROJECT_NAME);
    ESP_LOGI("app_init", "App version:      %s", PROJECT_VERSION);
    ESP_LOGI("app_init", "Compile time:     %s %s", PROJECT_BUILD_DATE, PROJECT_BUILD_TIME);
    ESP_LOGI("app_init", "===================================================");
}

static void test_system_metrics(void)
{
    ESP_LOGI("metrics_test", "=== System Metrics Test ===");
    
    // Test each metric individually
    for (int i = 0; i < METRIC_COUNT; i++) {
        system_metric_t metric = (system_metric_t)i;
        const char* description = get_metric_description(metric);
        const char* value = get_system_metric(metric);
        metric_error_t error = get_metric_error();
        
        if (error == METRIC_OK) {
            ESP_LOGI("metrics_test", "%-30s: %s", description, value);
        } else {
            ESP_LOGW("metrics_test", "%-30s: %s (Error: %d)", description, value, error);
        }
        
        // Small delay to prevent overwhelming the log output
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    
    ESP_LOGI("metrics_test", "=== End System Metrics Test ===");
}
