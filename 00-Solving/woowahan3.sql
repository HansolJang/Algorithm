SELECT
  team_id,
  team_name,
  (SUM(CASE
     WHEN host_team = team_id AND host_goals > guest_goals
       THEN 3
     WHEN guest_team = team_id AND guest_goals > host_goals
       THEN 3
     WHEN (host_team = team_id OR guest_team = team_id) AND host_goals = guest_goals
       THEN 1
     ELSE 0 END)) AS num_points
FROM teams, matches
GROUP BY team_id
ORDER BY num_points DESC, team_id ASC;