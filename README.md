# ESP32 Weather Station for Marine/Boat Applications

A comprehensive weather monitoring system designed for marine environments using ESP32 with ESP-IDF framework.

## Overview

This project implements a weather station specifically designed for boat and marine applications, providing real-time environmental monitoring including:

- Temperature and Humidity monitoring
- Barometric pressure readings  
- Wind speed and direction measurement
- GPS location tracking
- Water temperature sensing
- Weather data logging and transmission

## Hardware

- **Board**: DOIT ESP32 DEVKIT V1
- **Framework**: ESP-IDF v5.4.0
- **Development Environment**: PlatformIO with Visual Studio Code

## Project Structure

```
ESP32-WeatherStation-Boat/
├── src/                    # Source code files
├── include/                # Header files
├── lib/                    # Project libraries
├── test/                   # Unit tests
├── firmware/               # Firmware output
├── scripts/                # Build and utility scripts
├── Hardware/               # Hardware documentation
└── MyProgrammingSetup/     # Development environment setup
```

## Getting Started

### Prerequisites

- Visual Studio Code with PlatformIO extension
- ESP32 development board (DOIT ESP32 DEVKIT V1)
- macOS/Linux/Windows development environment

### Building and Flashing

```bash
# Clone the repository
git clone https://github.com/JohnDevine/ESP32-WeatherStation-Boat.git
cd ESP32-WeatherStation-Boat

# Build the project
pio run

# Upload to ESP32
pio run --target upload

# Monitor serial output
pio device monitor
```

## Features

- Real-time weather data collection
- Marine-specific environmental monitoring
- GPS integration for location tracking
- Data logging capabilities
- Low power consumption design
- Marine-grade environmental protection

## Configuration

The project uses PlatformIO for build management. Key configuration files:

- `platformio.ini` - Build configuration
- `sdkconfig.esp32doit-devkit-v1` - ESP-IDF specific settings
- `partitions.csv` - Flash memory partitioning

## Development Guidelines

This project follows ESP-IDF C coding standards:

- Snake_case for functions
- UPPER_CASE for constants
- Doxygen-style documentation
- ESP_LOG* for logging instead of printf
- Static memory allocation preferred

See `copilot.context.json` for detailed coding guidelines and project structure.

## Version Management

Version information is managed through build flags in `platformio.ini`. See `README.VERSIONING.md` for detailed versioning documentation.

## Testing

Unit tests are located in the `test/` directory using the Unity framework. Run tests with:

```bash
pio test
```

## Author

John Devine (john.h.devine@gmail.com)

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Weather Station Specific Features

### Marine Environment Considerations

- Corrosion-resistant sensor housing
- IP67/IP68 rated enclosures
- Salt water exposure protection
- Vibration and shock resistance
- Wide operating temperature range

### Data Collection

- Temperature: Air and water temperature monitoring
- Humidity: Relative humidity measurement
- Pressure: Barometric pressure with sea level correction
- Wind: Speed and direction measurement
- GPS: Location, speed, and heading
- Motion: Boat movement and stability monitoring

### Connectivity

- WiFi for shore-based data transmission
- Bluetooth for mobile device connectivity
- SD card for local data storage
- Optional cellular modem for offshore connectivity

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Troubleshooting

### Apple Silicon Compatibility

This project is configured for Apple Silicon (M1/M2/M3) compatibility using ESP-IDF 5.4.0. If you encounter build issues:

```bash
# Check ESP-IDF version
pio run -e esp32doit-devkit-v1 -v | grep DIDF_VER
```

### Common Issues

- **Build failures**: Ensure PlatformIO and ESP-IDF are properly installed
- **Upload failures**: Check USB connection and ESP32 board selection
- **Serial monitor issues**: Verify baud rate (115200) and COM port

For more troubleshooting information, see the Hardware documentation folder.
