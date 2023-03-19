
# # Insertion sort
# best case : O(n)
# worst case O(n^2)
# v = [int(x) for x in input("Numere lista: ").split()]

# for i in range(1,len(v)):
#     print(f"i={i}")
#     key = v[i]
#     j = i - 1
#     while j>=0 and key < v[j]:
#         v[j+1]=v[j]
#         j-=1
#     v[j+1]=key

# print(v)

#count sort(pe numere naturale)

#complexitate O(n+max)
#dimensiune O(n+max)
# v = [int(x) for x in input("Numere lista: ").split()]
# fr = [0]*(max(v)+1)
# for i in range(0,len(v)):
#     fr[v[i]]+=1

# poz = 0
# for i in range(0, len(fr)):
#     while fr[i] != 0:
#         v[poz] = i
#         fr[i]-=1
#         poz+=1
    
# print(v)

