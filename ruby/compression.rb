# Implement a method to perform basic string compression using the counts of repeated characters.
# For example, the string aabcccccaaa would become a2blc5a3.
# If the "compressed" string would not become smaller than the original string, your method should return the original string.










def compress(str)
    arr = []
    ret = ""
    str.chars.each do |c|
        if c == arr.last
            arr << c
        else
            ret += "#{arr.last}#{arr.length}" if arr.length > 0
            arr = [c]
        end
    end

    ret += "#{arr.last}#{arr.length}"

    if ret.length < str.length
        ret
    else
        str
    end
end

compress "aabcccccaaa"
