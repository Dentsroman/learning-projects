class TwoPointerSearch:

    def __init__(self, num_list, target):
        self.num_list = num_list
        self.target = target
        self.result = self.two_pointer_search(self.num_list, self.target)

    # Time complexity: O(n)
    # Space complexity: O(1)
    # The two-pointer search algorithm is a technique used to find a pair of elements in a sorted array that sum up to a target value.
    # The algorithm uses two pointers, one starting from the beginning of the array and the other starting from the end of the array.
    # The pointers move towards each other until they meet or the sum of the elements at the pointers is equal to the target value.
    # If the sum of the elements at the pointers is less than the target value, the left pointer is moved to the right.
    # If the sum of the elements at the pointers is greater than the target value, the right pointer is moved to the left.
    # The algorithm returns the indices of the elements that sum up to the target value.
    def two_pointer_search(self, num_list, target):
        left_pointer, right_pointer = 0, len(num_list) - 1

        while left_pointer < right_pointer:
            current_num = num_list[left_pointer] + num_list[right_pointer]
            if current_num == target:
                return [left_pointer, right_pointer]
            elif current_num < target:
                left_pointer += 1
            else:
                right_pointer -= 1

        return []


if __name__ == '__main__':
    num_list = [1, 2, 4, 5, 6]
    target = 9
    resultInstance = TwoPointerSearch(num_list, target)
    print(resultInstance.result)
