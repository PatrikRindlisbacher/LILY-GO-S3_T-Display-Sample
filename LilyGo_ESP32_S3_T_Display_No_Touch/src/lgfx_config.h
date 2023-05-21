// Liliygo S3 LCD T-Display ESP32S3R8  ST7789 Parallel8
//#define PIN_POWER_ON                 15                                                         // Noch klären wo der benutzt wird

#define LGFX_USE_V1                                                                               // User new Version 1
#include <LovyanGFX.hpp>                                                                          // Inlude LovyanGFX
class LGFX : public lgfx::LGFX_Device                                                             // Class LGFX Device
{
lgfx::Panel_ST7789  _panel_instance;                                                              // Panel Instanz
lgfx::Bus_Parallel8 _bus_instance;                                                                // Instanz bus paralelo de 8 bits 
lgfx::Light_PWM     _light_instance;                                                              // Instanz Hintergrund Beleuchtung 
public:
  LGFX(void)                                                                                      // Konstuktor
  {
    {                                                                                             // Realice ajustes de control de bus.
      auto cfg = _bus_instance.config();                                                          // Obtenga una estructura para la configuración del bus.
      cfg.freq_write = 2000000;                                                                   // Reloj de transmisión (hasta 20 MHz, redondeado al valor obtenido al dividir 80 MHz por un número entero)
      cfg.pin_wr = 8;                                                                             // WR 
      cfg.pin_rd = 9;                                                                             // RD 
      cfg.pin_rs = 7;                                                                             // RS(D/C) número de pin de conexión
      cfg.pin_d0 = 39;                                                                            // D0
      cfg.pin_d1 = 40;                                                                            // D1
      cfg.pin_d2 = 41;                                                                            // D2
      cfg.pin_d3 = 42;                                                                            // D3
      cfg.pin_d4 = 45;                                                                            // D4
      cfg.pin_d5 = 46;                                                                            // D5
      cfg.pin_d6 = 47;                                                                            // D6
      cfg.pin_d7 = 48;                                                                            // D7
      _bus_instance.config(cfg);                                                                  // Aplica el valor establecido al bus.
      _panel_instance.setBus(&_bus_instance);                                                     // Configure el bus en el panel.
    }
    {                                                                                             // Configure el control del panel de visualización.
      auto cfg = _panel_instance.config();                                                        // Zeigt die Erfassung der Struktur für die Panel-Einstellung an.
      cfg.pin_cs           = 6;                                                                   // CS   (-1 = disable)
      cfg.pin_rst          = 5;                                                                   // RST  (-1 = disable)
      cfg.pin_busy         = -1;                                                                  // BUSY (-1 = disable)
      cfg.panel_width      = 170;                                                                 // Pixel X
      cfg.panel_height     = 320;                                                                 // Pixel Y
      cfg.offset_x         = 35;                                                                  // Offset X
      cfg.offset_y         = 0;                                                                   // Offset Y
      cfg.offset_rotation  = 0;                                                                   //  0~7 
      cfg.dummy_read_pixel = 8;                                                                   // 
      cfg.dummy_read_bits  = 1;                                                                   // 
      cfg.readable         = true;                                                                // Establecer en verdadero si los datos se pueden leer
      cfg.invert           = true;                                                                // Invert Colors
      cfg.rgb_order        = true;                                                                // Se establece en verdadero si se intercambian el rojo y el azul del panel
      cfg.dlen_16bit       = false;                                                               // Establecido en verdadero para paneles que transmiten longitud de datos en unidades de 16 bits con paralelo de 16 bits o SPI
      cfg.bus_shared       = false;                                                               // Si el bus se comparte con la tarjeta SD, establezca en verdadero (control de bus con drawJpgFile, etc.)
      _panel_instance.config(cfg);
    }
    {                                                                                             // Retroiluminacion
      auto cfg = _light_instance.config();                                                        // Light_PWM
      cfg.pin_bl = 38;                                                                            // Light_PWM
      cfg.invert = false;                                                                         // Light_PWM
      cfg.freq   = 44100;                                                                         // Light_PWM
      cfg.pwm_channel = 7;                                                                        // Light_PWM 
      _light_instance.config(cfg);
      _panel_instance.setLight(&_light_instance);                                                 // 
    }
    setPanel(&_panel_instance); // Establece el panel a utilizar.
  }
};