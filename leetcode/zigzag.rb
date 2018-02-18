# https://leetcode.com/problems/zigzag-conversion/description/
# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
  rows = num_rows.times.to_a.map { "" }
  curr_row = 0
  going_down = true
  s.chars.each_with_index do |c, i|
    rows[curr_row] += c
    if curr_row == 0 && rows.size > 1
      curr_row += 1
      going_down = true
    elsif curr_row == (rows.size - 1)
      curr_row -= 1
      going_down = false
    elsif rows.size > 1
      if going_down
        curr_row += 1
      else
        curr_row -= 1
      end
    end
  end
  rows.join
end

puts (convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR")
puts convert("AB", 1)