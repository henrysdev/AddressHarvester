cmake_minimum_required(VERSION 2.8.9)
project(entry)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcurl")

add_executable(entry src/Harvester.cpp
                src/UrlFrontier.cpp
                src/UrlFrontier.h
                src/PageGrabber.cpp
                src/PageGrabber.h
                src/Parser.cpp
                src/Parser.h
                src/UrlFilter.h
                src/UrlFilter.cpp
                src/TextSearch.h
                src/TextSearch.cpp
                src/utils/HTTPDownloader.h
                src/utils/HTTPDownloader.cpp
                src/libs/gumbo-parser/src/attribute.c
                src/libs/gumbo-parser/src/attribute.h
                src/libs/gumbo-parser/src/char_ref.c
                src/libs/gumbo-parser/src/char_ref.h
                src/libs/gumbo-parser/src/char_ref.rl
                src/libs/gumbo-parser/src/error.c
                src/libs/gumbo-parser/src/error.h
                src/libs/gumbo-parser/src/gumbo.h
                src/libs/gumbo-parser/src/insertion_mode.h
                src/libs/gumbo-parser/src/parser.c
                src/libs/gumbo-parser/src/parser.h
                src/libs/gumbo-parser/src/string_buffer.c
                src/libs/gumbo-parser/src/string_buffer.h
                src/libs/gumbo-parser/src/string_piece.c
                src/libs/gumbo-parser/src/string_piece.h
                src/libs/gumbo-parser/src/tag.c
                src/libs/gumbo-parser/src/tag.in
                src/libs/gumbo-parser/src/tag_enum.h
                src/libs/gumbo-parser/src/tag_gperf.h
                src/libs/gumbo-parser/src/tag_sizes.h
                src/libs/gumbo-parser/src/tag_strings.h
                src/libs/gumbo-parser/src/token_type.h
                src/libs/gumbo-parser/src/tokenizer.c
                src/libs/gumbo-parser/src/tokenizer.h
                src/libs/gumbo-parser/src/tokenizer_states.h
                src/libs/gumbo-parser/src/utf8.c
                src/libs/gumbo-parser/src/utf8.h
                src/libs/gumbo-parser/src/util.c
                src/libs/gumbo-parser/src/util.h
                src/libs/gumbo-parser/src/vector.c
                src/libs/gumbo-parser/src/vector.h)

target_link_libraries(entry curl)