"""
Algorithm: Heap_Sort
Unstable, Non-recursive
Time-Complexity: Best - O(nlogn), Average - O(nlogn), Worst - O(nlogn)
"""
def heap_sort(array)
array_size = array.size
    adjusted_array = [nil] + array
    (array_size / 2).downto(1) do |i|
    heapify(adjusted_array, i, array_size)
  end
  while array_size > 1
    adjusted_array[1], adjusted_array[array_size] = adjusted_array[array_size], adjusted_array[1]  
    array_size -= 1
    heapify(adjusted_array, 1, array_size)
  end
  adjusted_array.drop(1)
end
 
# Heapify method to adjust heap downward
def heapify(adjusted_array, parent, limit)
  top = adjusted_array[parent]
  while (child = 2 * parent) <= limit
    child += 1  if child < limit and adjusted_array[child] < adjusted_array[child + 1]  
    break  if top >= adjusted_array[child]
    adjusted_array[parent] = adjusted_array[child]
    parent = child
  end
  adjusted_array[parent] = top
end
 
# heap_sort test
array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -15, -10, -4, -7].shuffle
print heap_sort(array)