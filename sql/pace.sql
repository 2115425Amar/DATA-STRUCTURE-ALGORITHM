SELECT customer_id, SUM(amount) AS total_spent
FROM sales
WHERE date >= CURRENT_DATE - INTERVAL '3 months'
GROUP BY customer_id
ORDER BY total_spent DESC
LIMIT 5;
