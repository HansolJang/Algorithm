# https://www.hackerrank.com/challenges/weather-observation-station-4/problem
select  count(CITY) - count(DISTINCT CITY) from station;