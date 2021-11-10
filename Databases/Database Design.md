# Database Design

When designing databases, I tend to strive for a very normalized structure (4NF or greater).

Some recent approaches I've taken to table design are:

## Common Table Structure

| Column        | Data Type     | Description/Usage                                                                                          |
| ------------- | ------------- | ---------------------------------------------------------------------------------------------------------- |
| *_KEY         | INT           | An internal surrogate key used for table joins. In some contexts, *_ID is preferred.                        |
| *_ID          | INT           | An alias for *_KEY. Used when KEY is considered an important part of the naming scheme to the context of the database. |
| COL           | ANY           | Generic columns with names based context of database/table.                                                |
| *_PUBLIC_ID   | VARCHAR(36)   | Generally a GUID/UUID, a value that unique identifies an entity within the context of the system utilizing the database. (i.e. if a database was designed for a restaurant menu, each item in the menu would have a *_PUBLIC_ID, which could be use to reference that specific item. Otherwise, other columns could be referenced, but potentially more ambiguously.) |
| MODIFIED_BY   | VARCHAR(32)   | Column that indicates which user last modified a value in a record.                                        |
| MODIFIED_DATE | DATE          | Column that indicated when the last modification occurred with a value in a record.                        |

While context is important in database design, I've found some common table structures I tend to re-implement in projects constantly:

## *_CATEGORY Table Structure

The \*_CATEGORY tables are tables that store categorical information in relative context with the subject matter. Generally, the MODIFIED_BY and MODIFIED_DATE columns from the common structure are included in these tables, but not \*_PUBLIC_ID. Common elements include:

| Column                | Data Type     | Description/Usage                                                                                          |
| --------------------- | ------------- | ---------------------------------------------------------------------------------------------------------- |
| CATEGORY_KEY          | INT           | An internal surrogate key used for joining a category table to a referencing table. In some contexts, *_ID is preferred. |
| CATEGORY_ID           | INT           | An alias for *_KEY. Used when KEY is considered an important part of the naming scheme to the context of the database. |
| CATEGORY_NAME         | VARCHAR(64)   | A column which references a specific type of category used in the system.                                  |
| CATEGORY_DESCRIPTION  | VARCHAR(1024) | A column which describes the category in more detail. This column may or may not be used for display purposes, depending on the context of the application. |

## TABLE1_TABLE2_PAIR Table Structure

The TABLE1_TABLE2_PAIR tables are tables where two other related tables are tied, where a one-to-many relationship is required beyond a parent-child relationship. Elements for this table type include:
| Column                | Data Type     | Description/Usage                                                                                          |
| --------------------- | ------------- | ---------------------------------------------------------------------------------------------------------- |
| PAIR_KEY              | INT           | An internal surrogate key used for unique identification of the pair record. Pair tables do not join with other tables, so this key is not used for joins. In some contexts, PAIR_ID is preferred. |
| PAIR_ID               | INT           | An alias for PAIR_KEY. Used when KEY is considered an important part of the naming scheme to the context of the database. |
| TABLE1_KEY/ID         | INT           | The surrogate key of one table to be paired (the first namesake of the *_PAIR table.)                      |
| TABLE2_KEY/ID         | INT           | The surrogate key of another table to be paired (the second namesake of the *_PAIR table.)                 |
| IS_*                  | BOOLEAN       | A property that is either True or False regarding the pair (i.e. IS_EDITABLE, IS_UNIQUE.) Also used when HAS_* is not gramatically correct. |
| HAS_*                 | BOOLEAN       | Similar to IS_*, but referencing a child or sub-entity, instead of self. (i.e. HAS_PROPERTY, HAS_ELEMENT.) Also used when IS_* is not grammatically correct. |
| CAN_*                 | BOOLEAN       | An action that can or cannot be performed wit the pair (i.e. CAN_READ, CAN_WRITE, CAN_EXECUTE.)            |

## B_* Table Structure

The B_* tables, or Backup tables, are tables that are exact replicas of existing database tables, which are copied to during database operations via a database trigger. These tables are designed to show change history, and act as a backup of the source table. These tables include:

| Column                | Data Type     | Description/Usage                                                                                          |
| --------------------- | ------------- | ---------------------------------------------------------------------------------------------------------- |
| B_*_KEY           | INT           | An internal surrogate key used for unique identification of the backup record. Backup tables do not join other tables, so this key is not used for joins. In some contexts, B_*_ID is preferred. |
| B_*_ID            | INT           | An alias for B_*_KEY. Used when KEY is considered an important part of the naming scheme to the context of the database. |
| B_*_DATE          | DATE          | The date in which the backup record was captured.                                                           |
| COL_BEFORE             | ANY           | The column value captured before an operation occurs. Will always be NULL on INSERT, and sometimes on UPDATE/DELETE. |
| COL_AFTER              | ANY           | The column value captured after an operation occurs. Will always be NULL on DELETE, and sometimes on INSERT/UPDATE. |

## Sequences

For KEY/ID fields (except *_PUBLIC_ID fields), I generally apply a sequence value upon insert into the table. Since I primarily use MySQL, this is handled within the database engine itself, and does not use explicitly defined sequences. However, in other database management systems (i.e. Oracle, etc.), a sequence must be defined. In those situations, I prefer naming the sequence: TABLE_SEQ[UENCE] (SEQ is used if name exceeds name limit of 30 characters. SEQUENCE is the preferred name. However, if SEQUENCE exceeds the limit, even by a character, SEQ is used.)

## Queries

When writing queries, I prefer to write them, when possible, in a multi-lined fashion. In PL/SQL (for Oracle database programming), I tend the following this format:

### All queries

For any query I write, I format elements of the query as such:

- Keywords (SELECT, INSERT, UPDATE, DELETE, NULL, IN, NOT, IS, AS, etc.) - all uppercase characters.
- Schema/User names - all uppercase characters.
- Table names - all uppercase characters.
- Column names - all lowercase characters.
- Aliases - all lowercase characters.

### SELECT statements

```sql
    SELECT
        alias1.column,
        alias1.column,
        alias2.column,
        ...
        aliasn.column
    FROM SCHEMA.TABLE alias1
    [
    JOIN SCHEMA.TABLE alias2 ON (alias1.column = alias2.column)
    JOIN SCHEMA.TABLE alias3 ON (alias2.column = alias3.column)
    ...
    JOIN SCHEMA.TABLE aliasn ON (aliasn-1.column = aliasn.column)
    WHERE (CONSTRAINT EXPRESSION)
    AND/OR (CONSTRAINT EXPRESSION)
    ...
    AND/OR (CONSTRAINT EXPRESSION)
    GROUP BY alias1.column, alias2.column, ..., aliasn.column
    HAVING (CONSTRAINT EXPRESSION)
    ORDER BY alias1.column, alias2.column, ..., aliasn.column
    LIMIT count OFFSET COUNT;
    ]
```

With this format, I prefer all columns to be explicitly defined in the query, on each line. The FROM clause is followed by schema/owner name dot table name (SCHEMA.TABLE), followed by a shorthand alias that makes sense in the context of the query. Joins follow the same structure, where the first column referenced is a table prior in the list, and the second column is within the table. I do not have a particular standard with the order of WHERE clauses, just whatever makes sense in the context of the statement itself. The closing semicolon for the statement is added to the end of the last line written, wether its the FROM statement, a JOIN statement, or a WHERE statement. Generally, I've hardly used GROUP BY, HAVING, and LIMIT statements in my SELECT queries.

### INSERT statements

```sql
    INSERT INTO SCHEMA.TABLE    (
                                    column,
                                    column,
                                    column,
                                    ...
                                    column
                                )
    VALUES                      (
                                    value,
                                    value,
                                    value,
                                    ...
                                    value
                                );
```

With INSERT statements, I prefer to write the INSERT INTO statement on a single line, with the open parenthesis for the column list (which is explicitly defined) tabbed over at least once. Then, for each column listed, it is tabbed until it passes the position of the open parenthesis. The column name is written, followed immediately by a comma. This continues until the last column is listed, where no comma is added to the end. The closing parenthesis is followed on the next line, tabbed to the same position as the open parenthesis. The VALUES keyword is aligned wtih the INSERT keyword, and the open parenthesis for the values is positioned in the same position as the prior set of parenthesis. Values are styled like columns, as well as the closing parenthesis for this set as well. The closing semicolon is added directly after the closing parenthesis. Values have the potential to be replaced by SELECT statements, where applicable. If utilized, those are structured much like SELECT statements previously mentioned.

### UPDATE statements

```sql
    UPDATE SCHEMA.TABLE alias
    SET alias.column = value,
        alias.column = value,
        ...
        alias.column = value
    [
    WHERE (CONSTRAINT EXPRESSION)
    AND/OR (CONSTRAINT EXPRESSION)
    ...
    AND/OR (CONSTRAINT EXPRESSION);
    ]
```

Much like INSERT and SELECT statements, UPDATE statements are formatted with the UPDATE statement on the first line, along with the schema name, table name, and alias. Then, on subsequent lines, starting with the first subsequent line, the SET keyword is used. Then, the column reference by with alias is tabbed over at least one time. A comma follows every line, except the last. Each column reference is lined up with the previous one. WHERE statements follow that of the SELECT statement WHERE clause.

### DELETE statements

```sql
    DELETE FROM SCHEMA.TABLE alias
    [
    WHERE  1=1
    ]
    or
    [
    WHERE   alias.column = value,
    AND/OR  alias.column = value,
    ...
    AND/OR  alias.column = value;
    ]
```

DELETE statements follow INSERT and UPDATE statements, by having the keyword, schema, table, and alias names on the first line. Then, either two WHERE clause conditions can occur:

- WHERE 1=1 - used when all records from the table need to be deleted.
- WHERE alias.column = value - common WHERE clause seen in other statements, like SELECT and UPDATE.

With the WHERE and AND/OR statements for DELETE statements, alias.column is tabbed until aligned, following the tabbing of the alias.column on the WHERE line.
