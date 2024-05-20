#include "tringlist.h"

#include <gtest.h>

TEST(TRingList, can_create_ringlist) {
	ASSERT_NO_THROW(TRingList<int> rl);
	TRingList<int> rl_1;
	EXPECT_EQ(rl_1.GetCurrent(), nullptr);
}


TEST(TRingList, can_copy_ringlist_from_first) {

	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	ASSERT_NO_THROW(TRingList<int> rl(a));
}


TEST(TRingList, copied_ringlist_from_pfirst_has_its_own_memory)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TRingList<int> rl(a);
	EXPECT_NE(b, rl.Search(53));
}


TEST(TRingList, can_copy_ringlist_from_list) {

	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	ASSERT_NO_THROW(TRingList<int> rl(l));
}


TEST(TRingList, copied_ringlist_from_list_has_its_own_memory)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TList<int> l(a);
	TRingList<int> rl(l);
	EXPECT_NE(l.Search(53), rl.Search(53));
}

TEST(TRingList, can_copy_ringlist_from_ringlist) {

	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TRingList<int> rl1(a);
	ASSERT_NO_THROW(TRingList<int> rl2(rl1));
}



TEST(TRingList, copied_ringlist_from_ringlist_has_its_own_memory)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TRingList<int> rl1(a);
	TRingList<int> rl2(rl1);
	EXPECT_NE(rl1.Search(53), rl2.Search(53));
}


//��� �����


TEST(TRingList, can_insert_pFirst)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TRingList<int> rl(a);
	rl.InsertFirst(51);
	EXPECT_EQ(51, rl.GetCurrent()->data);
	EXPECT_EQ(4, rl.GetSize());
}


TEST(TRingList, correct_insert_pFirst_1)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TRingList<int> rl(a);
	rl.InsertFirst(51);
	EXPECT_EQ(51, rl.GetCurrent()->pNext->pNext->pNext->pNext->pNext->data);

}


TEST(TRingList, correct_insert_pFirst_2)
{
	TNode<int>* c = new TNode<int>(54, nullptr);

	TRingList<int> rl(c);
	rl.InsertFirst(53);
	EXPECT_EQ(54, rl.GetCurrent()->pNext->pNext->pNext->pNext->data);
	EXPECT_EQ(53, rl.GetCurrent()->pNext->pNext->pNext->pNext->pNext->pNext->data);

}




TEST(TRingList, can_insert_after_current)
{
	TNode<int>* c = new TNode<int>(54, nullptr);
	TNode<int>* b = new TNode<int>(53, c);
	TNode<int>* a = new TNode<int>(52, b);

	TRingList<int> rl(a);
	rl.InsertFirst(51);
	ASSERT_NO_THROW(rl.InsertAfter(100));
}



//�������������� remove

TEST(TRingList, correct_remove_only_one_element)
{
	TNode<int>* a = new TNode<int>(52);

	TRingList<int> rl(a);
	rl.Remove(52);
	EXPECT_EQ(rl.GetCurrent(), nullptr);
}
