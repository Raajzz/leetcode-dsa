# Write your MySQL query statement below

# SELECT 
#     query_name, 
#     ROUND(AVG(rating/position), 2) AS quality,
#     ROUND(
#         (SELECT COUNT(*) FROM Queries WHERE rating < 3 AND query_name = query_name)/COUNT(query_name) * 100, 
#     2) AS poor_query_percentage
# FROM Queries
# GROUP BY query_name;
    
SELECT 
    query_name, 
    ROUND(AVG(rating/position), 2) AS quality,
    ROUND(AVG(rating<3)*100, 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name