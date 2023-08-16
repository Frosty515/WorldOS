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

#ifndef _TIME_H
#define _TIME_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ISO C data types */

typedef unsigned int time_t;

/* ISO C functions */

time_t time(time_t* timer);

/* Extra functions */

int64_t years_to_days_since_epoch(int year); // Turn year into days since 01/01/1970
int64_t days_since_epoch(int year, int month, int day); // Get days since 01/01/1970

#ifdef __cplusplus
}
#endif

#endif /* _TIME_H */