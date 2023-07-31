/*
Copyright (©) 2022-2023  Frosty515

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

#include "Bitmap.hpp"

namespace WorldOS {

    /* Bitmap class */

    /* Public methods */

    Bitmap::Bitmap() : m_Size(0), m_Buffer(nullptr) {

    }

    Bitmap::Bitmap(uint8_t* buffer, size_t size) : m_Size(size), m_Buffer(buffer) {
        
    }

    Bitmap::~Bitmap() {
        m_Size = 0;
        m_Buffer = nullptr;
    }

    bool Bitmap::operator[](uint64_t index) const {
        uint64_t byteIndex = index / 8;
        if (byteIndex >= m_Size)
            return false; // default is 0
        uint8_t bitIndex = index % 8;
        uint8_t bitIndexer = 0b10000000 >> bitIndex;
        if ((m_Buffer[byteIndex] & bitIndexer) > 0) {
            return true;
        }

        return false; // default is 0
    }

    void Bitmap::Set(uint64_t index, bool value) {
        uint64_t byteIndex = index / 8;
        if (byteIndex >= m_Size)
            return; // prevent memory errors
        uint8_t bitIndex = index % 8;
        uint8_t bitIndexer = 0b10000000 >> bitIndex;
        m_Buffer[byteIndex] &= ~bitIndexer;
        if (value) {
            m_Buffer[byteIndex] |= bitIndexer;
        }
    }

}