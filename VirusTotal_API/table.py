from tabulate import tabulate
import markdown_it


# Sample data for the table
data = [
    ["Name", "Age", "City"],
    ["Alice", 25, "New York"],
    ["Bob", 30, "Los Angeles"],
    ["Charlie", 22, "Chicago"]
]

data += [["dudi" , 31 , "bait shemesh"]]

# Print the table in a tabular format
table = tabulate(data, headers="firstrow", tablefmt="grid")
print(table)

Markdown = """
_Markdown_
"""
print(Markdown)

markdown_text = """
# Markdown Printing in Python

>You can print Markdown-formatted text in Python without using any external libraries by simply formatting your text as Markdown and then printing it. Markdown is a lightweight markup language that uses plain text to format text.

## Examples

### Headers

You can create headers by using one or more '#' symbols. For example:
"""

md = markdown_it.MarkdownIt()
html_output = md.render(markdown_text)

print(html_output)
print(markdown_text)
