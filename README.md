# In-Game Clock Suite
This feature branch creates a system that operates practically independent of the real time clock. It also includes macros that allow developers to dynamically change the time and date within their game. If you wish to create a hack with real-time elements (i.e. tied to real-life time), do NOT use this feature branch, as it assumes you want to create an in-game time system (i.e. something more akin to Minecraft, SV, and PLA).

## System of time
In its current set up, the branch has a default of 28 day months, and 12 month years. Because all the months have the same length, all Weekdays also fall under the same day every month. Lastly, the maximum amount of years a game can have is 65,535.

## New Macros
- `addtime`
    - `addtime(years, month, days, hours, minutes, seconds)`
    - This macro allows you to add a number of specific units of time. For example, if you wanted to add a specific amount of time to the current time.
    - For example, `addtime(1, 10, 27, 5, 15, 0)` advances time by 1 year, 10 months, 27 days, 5 hours, 15 minutes, and 0 seconds.
    - This also accounts for overlap (i.e. when adding time would cause it to got to the next unit of time), as the next biggest unit of time will have 1 added to it as well, and the smaller unit will be reset to 0.
        - Example 1: `addtime(1, 366, 0, 0, 0, 0)` will add 2 years, as 366 days = 1 year.
        - Example 2: Current ingame time is at 0 years, and 11 months. `addtime(0, 1, 0, 0, 0, 0)` shifts the time to year 1 and month 0.
- `settime`
    - `settime(years, month, days, hours, minutes, seconds)`
    - This sets the in-game time to a specified time in-game.
    - For example `settime(1, 2, 3, 4, 5, 6)` will set the in-game time to Year 1, Month 2, Day 3, Hour 4, Minute 5, and Second 6.

- Specific Unit Macros
    - Each unit of time has their own `add` and `set` variants, except for seconds.
    - `addyear`, `addmonth`, `addday`, `addhour`, `addminute`
    - `setyear`, `setmonth`, `setday`, `sethour`, `setminute`

## Menu Clocks integration
It's fairly simple to integrate the In-Game clock with menu clocks, such as Pawkkie's. Simply change any references to `gLocalTime.###`, where ### is a unit such as hours (gLocalTime.hour, gLocalTime.minute), and replace it with a respective Get function. All of these can be found below:
- GetYear()
- GetMonth()
- GetDay()
- GetHour()
- GetMinute()
- GetSecond()

## Special thanks:
- Mako for originally cracking how fake RTC and RTC originally interacted, and how to divorce them.
- RavePossum and SBird for teaching me how to write the script commands, and when to switch to using macro callnatives for them instead.