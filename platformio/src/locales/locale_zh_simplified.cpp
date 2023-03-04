/* Simplified Chinese locale settings for esp32-weather-epd.
 * Copyright (C) 2022-2023  Ricky Yel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "config.h"

#ifdef LOCALE_zh_CN

#include <vector>
#include <Arduino.h>
#include "_locale.h"

// TIME/DATE (NL_LANGINFO)
// locale-based information,
// see https://man7.org/linux/man-pages/man3/nl_langinfo.3.html for more info.
const char *LC_ABDAY[7] = {"日", "一", "二", "三", "四", "五", "六"};
const char *LC_DAY[7] = {"星期日", "星期一", "星期二", "星期三", 
                         "星期四", "星期五", "星期六"};
const char *LC_ABMON[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
                            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const char *LC_MON[12] = {"一月",    "二月",  "三月",    "四月", 
                          "五月",    "六月",  "七月",    "八月", 
                          "九月",    "十月",  "十一月",   "十二月"};
const char *LC_AM_PM[2] = {"上午", "下午"};
const char *LC_D_T_FMT    = "%a %d %b %Y %T";
const char *LC_D_FMT      = "%d/%m/%y";
const char *LC_T_FMT      = "%H:%M:%S";
const char *LC_T_FMT_AMPM = "%I:%M:%S %P";

// OWM LANGUAGE
// For full list of languages, see https://openweathermap.org/api/one-call-api#multi
// Note: "[only] The contents of the 'description' field will be translated."
const String OWM_LANG = "zh_cn";

// CURRENT CONDITIONS
const char *TXT_FEELS_LIKE         = "体感温度";
const char *TXT_SUNRISE            = "日出";
const char *TXT_SUNSET             = "日落";
const char *TXT_WIND               = "风速";
const char *TXT_HUMIDITY           = "湿度";
const char *TXT_UV_INDEX           = "紫外线指数";
const char *TXT_PRESSURE           = "气压";
const char *TXT_AIR_QUALITY_INDEX  = "空气质量";
const char *TXT_VISIBILITY         = "能见度";
const char *TXT_INDOOR_TEMPERATURE = "温度";
const char *TXT_INDOOR_HUMIDITY    = "湿度";

// UV INDEX
const char *TXT_UV_LOW       = "弱";
const char *TXT_UV_MODERATE  = "中等";
const char *TXT_UV_HIGH      = "强";
const char *TXT_UV_VERY_HIGH = "很强";
const char *TXT_UV_EXTREME   = "极强";

// WIFI
const char *TXT_WIFI_EXCELLENT     = "优秀";
const char *TXT_WIFI_GOOD          = "良好";
const char *TXT_WIFI_FAIR          = "正常";
const char *TXT_WIFI_WEAK          = "微弱";
const char *TXT_WIFI_NO_CONNECTION = "无连接";

// LAST REFRESH
const char *TXT_UNKNOWN = "未知";

// ALERTS
// The display can show up to 2 alerts, but alerts can be unpredictible in
// severity and number. If more than 2 alerts are active, the esp32 will attempt
// to interpret the urgency of each alert and prefer to display the most urgent 
// and recently issued alerts of each event type. Depending on your region 
// different keywords are used to convey the level of urgency.
//
// A vector array is used to store these keywords. Urgency is ranked from low to
// high where the first index of the vector is the least urgent keyword and the 
// last index is the most urgent keyword. Expected as all lowercase.
//
// Here are a few examples, uncomment the array for your region (or create your 
// own).
const std::vector<String> ALERT_URGENCY = {"蓝色", "黄色", "橙色", "红色"};                 // Chinese national weather service
// const std::vector<String> ALERT_URGENCY = {"statement", "watch", "advisory", "warning", "emergency"}; // US National Weather Service
// const std::vector<String> ALERT_URGENCY = {"yellow", "amber", "red"};                 // United Kingdom's national weather service (MET Office)
// const std::vector<String> ALERT_URGENCY = {"minor", "moderate", "severe", "extreme"}; // METEO
// const std::vector<String> ALERT_URGENCY = {}; // Disable urgency interpretation (algorithm will fallback to only prefer the most recently issued alerts)

// ALERT TERMINOLOGY
// Weather terminology associated with each alert icon
const std::vector<String> TERM_SMOG =
    {"霾"};
const std::vector<String> TERM_SMOKE =
    {"烟雾"};
const std::vector<String> TERM_FOG =
    {"雾"};
const std::vector<String> TERM_METEOR =
    {"流星"};
const std::vector<String> TERM_NUCLEAR =
    {"核辐射", "电离辐射"};
const std::vector<String> TERM_BIOHAZARD =
    {"生物灾害"};
const std::vector<String> TERM_EARTHQUAKE =
    {"地震"};
const std::vector<String> TERM_TSUNAMI =
    {"海啸"};
const std::vector<String> TERM_FIRE =
    {"火灾"};
const std::vector<String> TERM_HEAT =
    {"高温"};
const std::vector<String> TERM_WINTER =
    {"暴风雪", "冬天", "冰", "雪", "霰", "冷", "雨夹雪", 
     "寒风", "道路结冰", "霜", "冰雹"};
const std::vector<String> TERM_LIGHTNING =
    {"雷暴", "风暴", "单体风暴", "飑线", "超级单体风暴",
     "闪电"};
const std::vector<String> TERM_SANDSTORM =
    {"沙暴", "扬尘", "尘暴"};
const std::vector<String> TERM_FLOOD =
    {"洪水", "风暴潮", "水面荡漾", "浪涌", "巨浪", "涨潮",
     "风暴潮"};
const std::vector<String> TERM_VOLCANO =
    {"火山活动", "火山灰", "火山", "火山爆发"};
const std::vector<String> TERM_AIR_QUALITY =
    {"空气", "气滞", "污染"};
const std::vector<String> TERM_TORNADO =
    {"龙卷风"};
const std::vector<String> TERM_SMALL_CRAFT_ADVISORY =
    {"small craft", "wind advisory"};
const std::vector<String> TERM_GALE_WARNING =
    {"狂风"};
const std::vector<String> TERM_STORM_WARNING =
    {"风暴预警"};
const std::vector<String> TERM_HURRICANE_WARNING =
    {"飓风", "大风天气", "强风天气"};
const std::vector<String> TERM_HURRICANE =
    {"飓风", "热带风暴", "台风", "气旋"};
const std::vector<String> TERM_DUST =
    {"多尘", "风沙"};
const std::vector<String> TERM_STRONG_WIND =
    {"大风"};

#endif
