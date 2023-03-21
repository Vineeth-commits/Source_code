require 'rspec'
require 'benchmark'

# generate 100 million random numbers
arr = Array.new(100_000_000) { rand 10000 }

# algorithm for finding largest item in array
def new_max arr_elements
    max_val = 0

    arr_elements.each do |i|
        if i > max_val
            max_val = i
        end
    end

    max_val
end

# benchmark each implementation
Benchmark.bm(10) do |x|
    x.report('Each: ') { new_max(arr) }
    x.report('Sort: ') { arr.sort.last }
    x.report('Max: ') { arr.max }
end

# test the code
describe 'New Max method' do
  it 'returns the max value from an array efficiently' do
    test_array = [2, 4, 10, 3, 1]
    expect(new_max(test_array)).to eq(10)
  end
end
