#Given an array 'a',create a product array where product[i]==product of all elements except a[i]
#Time-complexity: O(n), Space-complexity: O(n),Auxiliary-space: O(1)

def product_array(a)
    len=a.length
    product=Array.new(len,1) # Initilaize product array elements to 1
    temp=1
    
    #Loop to store product of left elements
    for i in 0...len
        product[i]=temp
        temp*=a[i]
    end
    
    temp=1 #reset temp variable to 1
  
    #Loop to multiply stored left products with right products
    for i in (len-1).downto(0)
        product[i]*=temp
        temp*=a[i]
    end
    
    return product
end

product_array([1,2,3,4,5,6])  # => [720, 360, 240, 180, 144, 120]


# Calculate the product off all the non zero numbers in array, and then divide by each index
# if there are 2 or more than 2 zeros in array the , final array wll have all zeros

def product_array_alternate(a)
    len=a.length
    product=Array.new(len,0) # Initilaize product array elements to 0
    result=1 # product of all numbers except zeros
    zeros_count = 0 # count of zeros
    zeros_index = 0 # position of zero

    #Loop to calculate the product of all elements of array
    for i in 0...len
        if a[i] == 0
          zeros_index = i
          zeros_count += 1
          break if zeros_count > 1 # if there are 2 or more zeros
        elsif
            result*=a[i]
        end
    end

    if zeros_count < 1 # if there are no zeros, divide result with that number
        for i in 0...len
            product[i] = result/a[i]
        end
    elsif zeros_count == 1 # if there is only one zero
       product[zeros_index] = result
    end

    return product
end


product_array_alternate([1,2,3,4,5,6]) # => [720, 360, 240, 180, 144, 120]
product_array_alternate([1,2,3,4,0,6]) # => [0, 0, 0, 0, 144, 0]
