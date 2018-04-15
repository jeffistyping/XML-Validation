# XML Validation

When given an XML input file, this program will accurately validate if opening/closing tags are matched and closed in the right order. 

When valid, the program will output "Valid" and a table of each tag used in the XML file with its frequency. The program will output "Not Valid", when it detects a tag mismatch, an unclosed tag or an unopened closing tag. 

## Example 1

### Input 
```XML
<book id="bk101">
      <author>Laakmann McDowell, Gayle</author>
      <title>Cracking The Coding Interview</title>
      <genre>Technical</genre>
      <price>44.95</price>
      <publish_date>2015-07-01</publish_date>
      <description>Basically the bible for technical interviews</description>
   </book>
<book id="bk102">
      <author>Frost, Jack</author>
      <title>It's Cold</title>
      <genre>Fantasy</genre>
      <price>5.95</price>
      <publish_date>2000-12-16</publish_date>
      <description>It's cold outside and I wrote a book about it</description>
</book>
```

### Output
```
Valid
book: 2
author: 2
title: 2
genre: 2
price: 2
publish_date: 2
description: 2
```
## Example 2

### Input
```XML
<abc>
  <def>This Tag is closed correctly!</def>
  <ghi>This isn't!</def>
</abc>
```
### Output
```
NOT Valid
```
