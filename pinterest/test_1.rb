# Flatten a dictionary so: {‘key1’: 1, ‘key2’: {‘a’: 5, ‘b’: 6}} becomes {‘key1’: 1, ‘key2.a’: 5, ‘key2.b’: 6}

hash = {'key1' => 1, 'key2' => {'a' => 5, 'b' => 6} }

hash.keys.each_with_index do |k, i|
  value = hash[k]
  if value.class == Hash
    keys = value.keys
    values = value.values
    keys.each_with_index do |key, i|
      hash["#{k}.#{key}"] = values[i]
    end

    hash.delete(k)
  end
end

puts hash

# Run time: O(k^v)
