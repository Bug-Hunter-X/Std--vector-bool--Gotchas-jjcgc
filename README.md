This example demonstrates the potential performance pitfalls and unexpected behavior associated with using std::vector<bool> in C++.  The solution shows how to avoid these issues by using std::vector<char> or another suitable approach when individual boolean access is required.

**Problem:** std::vector<bool> optimizes storage by packing booleans into bits. However, this optimization comes at a cost: accessing individual elements is significantly slower and less intuitive than with a regular vector.

**Solution:** For most use cases, using a `std::vector<char>` or `std::vector<int>` (depending on boolean vector size) is more efficient and predictable, despite being less memory-efficient in storage.
