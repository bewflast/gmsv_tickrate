# gmsv_tickrate
Get current server's performance stats from tickrate without fucking with time's functions

# RU

[Запрос](https://github.com/Facepunch/garrysmod-requests/issues/1996) на добавление сервер-сайд функции [`engine.ServerFrameTime()`](https://wiki.facepunch.com/gmod/engine.ServerFrameTime) был помечен, как "не планируется"
(кто бы сомневался), поэтому я решил написать маленький модуль, который предоставляет доступ к фрейм тайму сервера и позволяет обнаружить просадки тикрейта без использования функций, связанных со временем.

--------------

### Скачивание

Скачать бинарники можно из [артефактов](https://github.com/bewflast/gmsv_tickrate/actions) (бинарники, собирающиеся через GitHub actions), либо из [последнего релиза](https://github.com/bewflast/gmsv_tickrate/releases/tag/Latest)

--------------

### Сборка
Проект использует [gm_common](https://github.com/danielga/garrysmod_common) как основу для бинарных модулей и [premake](https://github.com/premake/premake-core) как генератор файлов систем сборок.
 Этапы сборки подробно расписаны [вот здесь](https://github.com/bewflast/gmsv_tickrate/blob/main/.github/workflows/build.yml).
 
--------------

### Использование

`require("tickrate")` - подгрузить модуль

`engine.HostFrameTime()` - получить время между тиками

`util.GetServerTickrate()` - получить текущий тикрейт

[В РАЗРАБОТКЕ!!!] `util.SetServerTickrate(num)` - изменить тикрейт

------------------
-----------------
-----------------

# ENG
[Feature request](https://github.com/Facepunch/garrysmod-requests/issues/1996) about `FrameTime()`'s server-side Lua function static value and that [`engine.ServerFrameTime()`](https://wiki.facepunch.com/gmod/engine.ServerFrameTime) is only client-side was marked as "Not planned" (wow) so i decided to write tiny module that will give access to the server's frame time and it will help detect tickrate's decreasing.

--------------

### Downloading
You can download binaries from [last's run artifacts](https://github.com/bewflast/gmsv_tickrate/actions/) or from [latest release](https://github.com/bewflast/gmsv_tickrate/releases/tag/Latest)

--------------

### Building

Project requires [gm_common](https://github.com/danielga/garrysmod_common) and [premake](https://github.com/premake/premake-core)
All building steps for Windows and Linux platforms you can find [here](https://github.com/bewflast/gmsv_tickrate/blob/main/.github/workflows/build.yml)

--------------

### Usage

`require("tickrate")` - load module

`engine.HostFrameTime()` - get server's frametime

`util.GetServerTickrate()` - get server's tickrate

[COMING SOON!!!] `util.SetServerTickrate(num)` - change tickrate to `num` value
