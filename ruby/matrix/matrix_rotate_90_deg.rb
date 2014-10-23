# Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
# write a method to rotate the image by 90 degrees Can you do this in place?
# Book: cracking the coding interview - Arrays and Strings  - pg. 101

require_relative '../matrix'
require "benchmark"

def rotate_90_deg(matrix)
  rotated = Matrix.new(35.times.map{ 0 }, 6)

  matrix.rows.each_with_index do |e, y|
    e.each_with_index do |elem, x|
      rotated.set(x, rotated.num_columns - y - 1, elem)
    end
  end

  rotated
end

matrix = Matrix.new((0..35).to_a, 6)
puts 'input:'
matrix.pretty_print
puts "\noutput:"
rotate_90_deg(matrix).pretty_print
