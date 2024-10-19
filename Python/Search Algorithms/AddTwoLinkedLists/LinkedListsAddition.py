class LinkedListsAddition:

    def __init__(self, l1, l2):
        self.l1 = l1
        self.l2 = l2
        self.result = self.linked_list_addition(self.l1, self.l2)

    def linked_list_addition(self, l1, l2):

        str_list1 = [str(num) for num in l1]
        str_list2 = [str(num) for num in l2]

        concatenated_str1 = ''.join(str_list1)
        concatenated_str2 = ''.join(str_list2)

        reversed_int1 = int(str(concatenated_str1)[::-1])
        reversed_int2 = int(str(concatenated_str2)[::-1])

        stringresult1 = int(reversed_int1)
        stringresult2 = int(reversed_int2)

        print(f'{stringresult1} \n {stringresult2}')

        sumresult = str(stringresult1 + stringresult2)
        sumresultlength = len(str(sumresult))

        return result


if __name__ == '__main__':
    l1 = [1,2,3]
    l2 = [2,2]
    resultInstance = LinkedListsAddition(l1, l2)
    print(resultInstance.result)
