/*

quoted_printable.hpp
--------------------

Copyright (C) Tomislav Karastojkovic (http://www.alepho.com).

Distributed under the FreeBSD license, see the accompanying file LICENSE or
copy at http://www.freebsd.org/copyright/freebsd-license.html.

*/


#pragma once

#include <string>
#include <vector>
#include "codec.hpp"


namespace mailio
{


/**
Quoted printable codec.
**/
class quoted_printable : public codec
{
public:

    /**
    Calls `codec::codec(line_len_policy_t)`.

    @param line_policy Line length policy to set.
    **/
    quoted_printable(codec::line_len_policy_t line_policy = codec::line_len_policy_t::NONE);

    quoted_printable(const quoted_printable&) = delete;

    quoted_printable(quoted_printable&&) = delete;

    /**
    Calls parent destructor.
    **/
    ~quoted_printable() = default;

    void operator=(const quoted_printable&) = delete;

    void operator=(quoted_printable&&) = delete;

    /**
    Encodes string into vector of quoted printable encoded strings by applying the line policy.

    @param text        String to encode.
    @return            Vector of quoted printable strings.
    @throw codec_error Bad crlf sequence.
    **/
    std::vector<std::string> encode(const std::string& text) const;

    /**
    Decodes vector of quoted printable strings to string by applying the line policy.

    @param text        Vector of quoted printable encoded strings.
    @return            Decoded string.
    @throw codec_error Bad line policy.
    @throw codec_error Bad character.
    @throw codec_error Bad hexadecimal digit.
    **/
    std::string decode(const std::vector<std::string>& text) const;

private:

    /**
    Check if the character is in the Quoted Printable character set.

    @param ch  Character to check.
    @return    True if it is, false if not.
    **/
    bool is_allowed(char ch) const;
};


} // namespace mailio
