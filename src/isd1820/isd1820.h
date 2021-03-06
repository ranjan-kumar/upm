/*
 * Author: Jon Trulson <jtrulson@ics.com>
 * Copyright (c) 2015 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#pragma once

#include <iostream>

#include <mraa/gpio.h>

namespace upm {
    /**
     * @brief UPM support for the ISD1820 based Grove Recorder
     * @defgroup isd1820 libupm-isd1820
     * @ingroup seeed gpio sound
     */

    /**
     * @library libupm-isd1820
     * @sensor isd1820
     * @comname Grove Recorder v1.0
     * @type sound
     * @man seeed
     * @con gpio
     *
     * @brief C++ API support for the ISD1820 based Grove Recorder
     *
     * This class implements support for the Grove Recorder.  There
     * are two digital pins, one that enables recording, and the other
     * that plays back what was previously recorded.
     *
     * @snippet isd1820.cxx Interesting
     */
  class ISD1820 {
  public:

    /**
     * ISD1820 module constructor
     *
     * @param recPin the pin to use for recording
     * @param playPin the pin to use for playback
     */
    ISD1820(int playPin, int recPin);

    /**
     * ISD1820 module Destructor
     */
    ~ISD1820();

    /**
     * Start or stop playback
     *
     * @param enable start playback if true, stop if false
     */
    void play(bool enable);

    /**
     * Start or stop recording
     *
     * @param enable start recording if true, stop if false
     */
    void record(bool enable);

  private:
    mraa_gpio_context m_gpioRec;
    mraa_gpio_context m_gpioPlay;
  };
}


