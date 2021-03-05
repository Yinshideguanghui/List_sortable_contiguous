#include"sortable_list_contiguous.h"

template <class List_entry>		//����λ��
int Sortable_list<List_entry>::max_key(int low, int high)
{
	int largest, current;
	largest = low;
	for (current = low + 1; current <= high; current++)
		if (List<List_entry>::entry[largest] < List<List_entry>::entry[current])
			largest = current;
	return largest;
}

template <class List_entry>		//����
void Sortable_list<List_entry>::Swap(int low, int high)
{
	if (low != high)	//low����high����ִ��
	{
		List_entry temp = List<List_entry>::entry[low];
		List<List_entry>::entry[low] = List<List_entry>::entry[high];
		List<List_entry>::entry[high] = temp;
	}
}

template <class List_entry>		//ѡ������
void Sortable_list<List_entry>::selection_sort()
{
	for (int position = List<List_entry>::count - 1; position > 0; position--)
	{
		int Max = max_key(0, position);
		Swap(Max, position);
	}
}

template <class List_entry>		//ϣ�������ڲ���������
void Sortable_list<List_entry>::sort_interval(int start, int increment)
{
	int first_unsorted;
	int position;
	List_entry current;
	for (first_unsorted = start + increment; first_unsorted < List<List_entry>::count; first_unsorted += increment)
		if (List<List_entry>::entry[first_unsorted] < List<List_entry>::entry[first_unsorted - increment])
		{
			position = first_unsorted;
			current = List<List_entry>::entry[position];
			do {
				List<List_entry>::entry[position] = List<List_entry>::entry[position - increment];
				position -= increment;
			} while (position > 0 && List<List_entry>::entry[position - increment] > current);
			List<List_entry>::entry[position] = current;
		}
}

template <class List_entry>		//ϣ������
void Sortable_list<List_entry>::shell_sort()
{
	int increment, start;
	increment = List<List_entry>::count;
	do {
		increment = increment / 3 + 1;		//�ӱ���Ԫ����ԭ���ڵļ��
		for (start = 0; start < increment; start++)
			sort_interval(start, increment);
	} while (increment > 1);
}