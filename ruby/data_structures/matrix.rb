# Simple 2D matrix backed by an array
class Matrix < Array
  def initialize(arr, num_columns)
    super(arr)
    @num_columns = num_columns
  end

  def at(x, y)
    idx = index_for(x, y)
    return -1 if idx >= size
    self[idx]
  end

  def index_for(x, y)
    (@num_columns * y) + x
  end

  def set(x, y, val)
    idx = index_for(x, y)
    return if idx >= size
    self[idx] = val
  end

  def num_columns
    @num_columns
  end

  def num_rows
    (size.to_f / @num_columns).ceil
  end

  def columns
    num_columns.times.map do |x|
      num_rows.times.map do |y|
        self.at(x, y)
      end
    end
  end

  def rows
    num_rows.times.map do |y|
      num_columns.times.map do |x|
        self.at(x, y)
      end
    end
  end

  def pretty_print
    return if empty?

    puts

    each_with_index do |e, i|
      if i == 0 || (i / @num_columns) == ((i - 1) / @num_columns)
        # next item is in same column
        STDOUT.print "#{('%02.0f' % e)} "
      else
        # next item is in next row
        STDOUT.print "\n#{('%02.0f' % e)} "
      end
    end
    if size % @num_columns != 0
      (size % @num_columns).upto(@num_columns - 1) do |i|
        STDOUT.print "xx "
      end
    end
    puts "\n"
  end
end
