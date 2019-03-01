# https://www.hackerrank.com/challenges/weather-observation-station-3/problem
select CITY from STATION where ID % 2 = 0 group by CITY;