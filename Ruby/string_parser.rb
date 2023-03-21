require "rspec"

# sample array of strings
string_array = [
  "Web IconHTML & CSS100%",
  "Command LineLearn the Command Line100%",
  "Ruby IconRuby50%",
  "Rails IconLearn Ruby on Rails100%",
  "Git IconLearn Git100%",
  "SassLearn Sass20%",
  "JQuery IconjQuery1%",
  "Angular JSLearn AngularJS 1.X100%",
  "Javascript IconLearn JavaScript55%"
]

# function for string parsing
def string_parser string_array
    # init empty array
    final_array = []
    # find and extract the percentages from the sample array
    string_array.each do |str|
        final_array << str.scan(/\d+/).last.to_i
    end
    # return array
    final_array
end

# print inspect the final array
p string_parser(string_array)

# test the code
describe "String Parser" do
    it "can take a string and output the correct values" do
        expect(string_parser(string_array)).to eq([100, 100, 50, 100, 100, 20, 1, 100, 55])
    end
end
