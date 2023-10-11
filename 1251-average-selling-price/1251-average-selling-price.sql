# Write your MySQL query statement below

SELECT p.product_id, 
IFNULL(round(sum((units * price))/sum(units), 2), 0) as average_price
FROM Prices p 
LEFT JOIN
UnitsSold u
ON p.product_id = u.product_id
AND purchase_date BETWEEN start_date AND end_date
GROUP BY (p.product_id);