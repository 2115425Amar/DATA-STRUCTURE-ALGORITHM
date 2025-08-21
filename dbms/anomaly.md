## **1. Insertion Anomaly**

**Problem:** You **cannot insert new data** because some unrelated data is missing.

**Example:**
Imagine a single table `Student_Course`:

| StudentID | StudentName | CourseID | CourseName |
| --------- | ----------- | -------- | ---------- |
| 1         | Amar        | C101     | SQL Basics |

* Suppose you want to **add a new course** (C102 – Python) that no student has enrolled in yet.
* You **can’t insert the course** without assigning it to a student first — because the table mixes student and course data.

**Why bad?** Data is locked together unnecessarily.

---

## **2. Update Anomaly**

**Problem:** If data appears multiple times, **updating it in one place but not others leads to inconsistency**.

**Example:**
Same table:

| StudentID | StudentName | CourseID | CourseName |
| --------- | ----------- | -------- | ---------- |
| 1         | Amar        | C101     | SQL Basics |
| 2         | Qwerty       | C101     | SQL Basics |

* If *CourseName* changes from *SQL Basics* to *Advanced SQL*, you must update it **everywhere**.
* If you forget one row → inconsistent data (some rows say “SQL Basics,” others say “Advanced SQL”).

**Why bad?** Causes data mismatches.

---

## **3. Deletion Anomaly**

**Problem:** Deleting some data **accidentally removes other valuable data**.

**Example:**
Same table:

| StudentID | StudentName | CourseID | CourseName |
| --------- | ----------- | -------- | ---------- |
| 1         | Amar        | C101     | SQL Basics |

* If Amar drops the course and you delete this row, you also lose the information **that Course C101 exists at all**.

**Why bad?** You lose data unintentionally.

---

## **Quick Summary**

* **Insertion anomaly:** Can’t insert data without unrelated data.
* **Update anomaly:** Same info in many places → inconsistent updates.
* **Deletion anomaly:** Removing data deletes other needed info too.

**Solution → Normalize the database** (split into separate tables: `Student`, `Course`, and `Enrollment`).