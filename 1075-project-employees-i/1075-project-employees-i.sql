# Write your MySQL query statement below

SELECT Project.project_id, ROUND(AVG(Employee.experience_years), 2) as average_years
FROM Project INNER JOIN Employee 
ON Project.employee_id = Employee.employee_id
GROUP BY Project.project_id;