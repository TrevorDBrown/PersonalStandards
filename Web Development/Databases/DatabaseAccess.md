# Database Access
Database access control is a problem in software development that is important, and offers a lot of solutions. My personal solution is that of a query dictionary/query processing engine model: 

- Request for a query is made to the query processing engine for a query, passing in input if needed.
- The query processing engine looks up the query from the query dictionary (support/db/queries.json).
- If found, and no input is required, the query processing engine runs the query, and returns the results to the calling function.
- If found, input is required, and input is provided, the query processing engine sanitizes and injects the provided input into the query (called instantiating a query, resulting in a query instance)
- If found, input is required, but no input is provided, an error is returned to the calling function stating the query needs inputs. 
- If not found, an error is returned to the calling function stating the query does not exist.
- Once the query is found and input is sanitized and injected, the query processing engine executes the query, and returns the result to the calling function.

I believe this solution can reduce redundant queries by making one query accessible in multiple places, reduce (or possibly eliminate, if done properly) SQL injection by preparing queries from a template, and sanitizing the provided inputs (if needed), and make it easier to call queries (i.e. instead of preparing SQL statements, a statement can be referenced by a shorthand name).