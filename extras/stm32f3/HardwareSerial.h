/*
   HardwareSerial.h : UART support for STM32F3 boards

   Copyright (C) 2018 Simon D. Levy 

   This file is part of Hackflight.

   Hackflight is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Hackflight is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Hackflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

extern "C" {

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>

    class HardwareSerial {

        protected:

            void *  _uart;

        public:

            uint8_t available(void);

            uint8_t read(void);

            void write(uint8_t byte);

            void flush(void);

            void printf(const char * fmt, ...)
            {
                va_list ap;       
                va_start(ap, fmt);     
                char buf[1000];
                vsprintf(buf, fmt, ap);
                for (char *p=buf; *p; p++)
                    this->write(*p);
                va_end(ap);  
                this->flush();
            }
    };

    class HardwareSerial1 : public HardwareSerial {

        public:

            void begin(uint32_t baud);

            uint8_t read(void);
    };
    extern HardwareSerial1 Serial1;

    class HardwareSerial2 : public HardwareSerial {

        public:

            void begin(uint32_t baud);

            uint8_t read(void);
    };
    extern HardwareSerial2 Serial2;

    class HardwareSerial3 : public HardwareSerial {

        public:

            void begin(uint32_t baud);

            uint8_t read(void);
    };
    extern HardwareSerial3 Serial3;

} // extern "C"
