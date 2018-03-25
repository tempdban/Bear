/*  Copyright (C) 2012-2017 by László Nagy
    This file is part of Bear.

    Bear is a tool to generate compilation database for clang tooling.

    Bear is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bear is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

namespace pear {

    struct LibraryConfig {
        const char *wrapper;
        const char *library;
        const char *target;
    };

    struct ExecutionConfig {
        const char **command;
        const char *file;
        const char *search_path;
    };

    struct Arguments {
        LibraryConfig forward;
        ExecutionConfig execution;
        bool verbose;
    };

    using continuation_t = int (*)(const char **);
    int call(Arguments const &args, continuation_t forward) noexcept;
}