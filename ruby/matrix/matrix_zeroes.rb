# Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column is set to 0
# Book: cracking the coding interview - Arrays and Strings

require_relative './matrix'
require "benchmark"

def matrix_zero_solution_1(matrix)
  0.upto(matrix.num_rows - 1) do |y|
    0.upto(matrix.num_columns - 1) do |x|
      if matrix.at(x, y) == 0
        0.upto(matrix.num_columns - 1) { |x1| matrix.set(x1, y, 'R') }
        0.upto(matrix.num_rows - 1) { |y1| matrix.set(x, y1, 'R') }
      end
    end
  end

  matrix.each_with_index do |e, i|
    matrix[i] = 0 if e == 'R'
  end
end

def matrix_zero_solution_2(matrix)
  rows = matrix.num_rows.times.map { 0 }
  cols = matrix.num_columns.times.map { 0 }

  0.upto(matrix.num_rows - 1) do |y|
    0.upto(matrix.num_columns - 1) do |x|
      if matrix.at(x, y) == 0
        cols[x] = 1
        rows[y] = 1
      end
    end
  end

  cols.each_with_index do |c, x|
    rows.each_with_index do |r, y|
      if r == 1 || c == 1
        matrix.set(x, y, 0)
      end
    end
  end
end

matrix = Matrix.new(30.times.map { rand > 0.92 ? 0 : 11 }, [4, 5, 6, 7].shuffle.first)

puts 'input:'
matrix.pretty_print

matrix_zero_solution_2(matrix)

puts "\noutput:"
matrix.pretty_print

Benchmark.bm(7) do |x|
  x.report("solution 1:") do
    matrix = Matrix.new(5_000_000.times.map { rand > 0.95 ? 0 : 1 }, 6)
    matrix_zero_solution_1(matrix)
  end

  x.report("solution 2:") do
    matrix = Matrix.new(5_000_000.times.map { rand > 0.95 ? 0 : 1 }, 6)
    matrix_zero_solution_2(matrix)
  end
end
