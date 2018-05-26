		ListNode* ptarg = lst;
		ListNode* pcurr = null;
		ListNode* pprev = null;

		while(ptarg && ptarg->next)
		{

			//search the whole list to find duplicates
			pcurr = ptarg->next;
			pprev = ptarg;
			while(pcurr)
			{
				if(pcurr->val == ptarg->val) 
				{
					//delete duplicates
					pprev->next = pcurr->next;
					delete pcurr;
					pcurr = pprev;
				}

				pprev = pcurr;
				pcurr = pcurr->next;
			}

			ptarg = ptarg->next;
		}