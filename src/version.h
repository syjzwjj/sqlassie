/*
 * SQLassie - database firewall
 * Copyright (C) 2011 Brandon Skari <brandon.skari@gmail.com>
 *
 * This file is part of SQLassie.
 *
 * SQLassie is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * SQLassie is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SQLassie. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SRC_VERSION_H_
#define SRC_VERSION_H_

const char* sqlassieVersion()
{
    return "(Development)";
}

const char* sqlassieName()
{
    return "SQLassie";
}

const char* sqlassieCopyright()
{
    return "Copyright (C) 2011 Brandon Skari";
}

const char* sqlassieShortLicense()
{
    return
"This is free software; see the source for copying conditions. There is NO\nwarranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE."; // NOLINT(whitespace/line_length)
}

#endif  // SRC_VERSION_H_
