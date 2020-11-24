/*
 modbus_registers.h - Modbus Registers Structure
 Copyright (C) 2020 Germain Masse

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef SRC_MODBUS_REGISTERS_H_
#define SRC_MODBUS_REGISTERS_H_

#include "Arduino.h"

typedef enum {
    MODBUS_TYPE_HOLDING = 0x00,         /*!< Modbus Holding register. */
    MODBUS_TYPE_HOLDING_F = 0x01,         /*!< Modbus 2 Holding registers */
//    MODBUS_TYPE_INPUT,                  /*!< Modbus Input register. */
    MODBUS_TYPE_COIL = 0x02,                   /*!< Modbus Coils. */
//    MODBUS_TYPE_DISCRETE,               /*!< Modbus Discrete bits. */
//    MODBUS_TYPE_COUNT,
//    MODBUS_TYPE_UNKNOWN = 0xFF
} modbus_entity_t;

typedef enum {
//    REGISTER_TYPE_U8 = 0x00,                   /*!< Unsigned 8 */
    REGISTER_TYPE_U16 = 0x01,                  /*!< Unsigned 16 */
//    REGISTER_TYPE_U32 = 0x02,                  /*!< Unsigned 32 */
    REGISTER_TYPE_FLOAT = 0x03,                /*!< Float type NOT FINISHED!!!!*/
//    REGISTER_TYPE_ASCII = 0x04,                 /*!< ASCII type */
    REGISTER_TYPE_DIEMATIC_ONE_DECIMAL = 0x05,
    REGISTER_TYPE_BITFIELD = 0x06,
    REGISTER_TYPE_DEBUG = 0x07
} register_type_t;

typedef union {
    const char* bitfield[16];
} optional_param_t;

typedef struct {
    uint16_t            id;
    modbus_entity_t     modbus_entity;      /*!< Type of modbus parameter */
    register_type_t     type;               /*!< Float, U8, U16, U32, ASCII, etc. */
    const char*         name;
    optional_param_t    optional_param;
} modbus_register_t;

const modbus_register_t registers[] = {
    { 1, MODBUS_TYPE_COIL, REGISTER_TYPE_U16, "Start" },
    { 37, MODBUS_TYPE_HOLDING, REGISTER_TYPE_U16, "Stages" },
    { 38, MODBUS_TYPE_HOLDING_F, REGISTER_TYPE_FLOAT, "Y_out" },
    { 33, MODBUS_TYPE_HOLDING_F, REGISTER_TYPE_FLOAT, "Setpoint" },
    { 35, MODBUS_TYPE_HOLDING_F, REGISTER_TYPE_FLOAT, "Room_T" },
    { 27, MODBUS_TYPE_HOLDING_F, REGISTER_TYPE_FLOAT, "Strip_1_T" },
    { 29, MODBUS_TYPE_HOLDING_F, REGISTER_TYPE_FLOAT, "Strip_2_T" },
    { 31, MODBUS_TYPE_HOLDING_F, REGISTER_TYPE_FLOAT, "Strip_3_T" }
   
 };

#endif  // SRC_MODBUS_REGISTERS_H_
