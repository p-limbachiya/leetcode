# Write your MySQL query statement below
SELECT w.id FROM Weather w JOIN Weather r ON DATEDIFF(w.recordDate,r.recordDate) = 1 AND w.temperature > r.temperature;