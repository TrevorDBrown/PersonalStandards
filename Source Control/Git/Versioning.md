# Versioning

When dealing with source control systems (or software engineering in general), versioning is a concern on how to manage builds of products.

Personally, I have a few preferences on the versioning scheme I use. If allowed, I follow a date of release, or calendar, versioning. That format is:

- YYYY.MM\[.DD.B\]
  - "YYYY" is the year (required)
  - "MM" is the month (required)
  - "DD" is the day (semi-optional - depends on the frequency of releases.)
  - "B" is a build number (optional - generally 0, but increments by 1 for each release on that day, if necessary.)

Examples of this include:

- 2021.02.18 - public build, released on February 18th, 2021. (implicit .0)
- 2020.12 - public build, release in December, 2020. (monthly, or less frequent, builds)
- 2000.01.01.8 - public build, released on January 1st, 2000 (9th release that day, index starts at 0)

In some cases, this all may vary, due to build system limitations. In those exceptions, the following may be used:

- Dates without leading zeroes may be required. Using the previous examples:
  - 2021.2.18 - public build, released on February 18th, 2021 (implicit .0)
  - 2020.12 - public build, released in December, 2020. (monthly, or less frequent, builds)
  - 2000.1.1.8 - public build, released on January 1st, 2000 (9th release that day, index starts at 0)

- Sometimes, dates are not allowed when versioning. Therefore, a more classical "Major.Minor.Build.Revision" scheme is used:
  - 0.1.0.0 - version 0, minor version 1 (pre-release, beta, etc.)
  - 1.0.0.0 - version 1 (initial major release)
  - 3.8.0.1 - version 3, minor version 8, build 0, revision 1

Personally, I'm more in favor of the date scheme with leading zeroes, since that is a quick glance indicator of the age of a release of software. Additionally, since these types of schemes do not implicitly define a difference between a pre-release variant and a public release, I prefer to explicitly add modifiers to the end of the build number, and other build variations beyond a public release. This modifier appends a string to the end of the version string. Those modifier strings are:

- alpha - alpha build: a pre-release build of a product.
- beta - beta build: more refined than alpha, but still a pre-release.
- nightly - nightly build: if the project is continuously updated with features, the nightly build is a "mostly" stable, quick release of the software. Minimal testing has been performed.
- canary - canary build: much like the nightly build, the canary build is a quick release of the software with any new features. Minimal to no testing has been performed.
- special - special build: a special build (i.e. build for a specific purpose, build for a special deadline, etc.)