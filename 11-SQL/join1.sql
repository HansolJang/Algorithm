#https://www.hackerrank.com/challenges/asian-population/problem
select sum(city.population) from city, country where city.countrycode = country.code and country.continent = 'Asia';