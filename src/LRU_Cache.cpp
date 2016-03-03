class LRUCache {
public:
	struct CacheEntry
	{
	public:
		int key;
		int value;
		CacheEntry(int k, int v) : key(k), value(v) {}
	};

	LRUCache(int capacity) {
		m_capacity = capacity;
	}

	int get(int key) {
		if (m_map.find(key) == m_map.end())
			return -1;

		MoveToHead(key);
		return m_map[key]->value;
	}

	void set(int key, int value) {
		if (m_map.find(key) == m_map.end())
		{
			CacheEntry newItem(key, value);
			if (m_LRU_cache.size() >= m_capacity)
			{
				//remove from tail
				m_map.erase(m_LRU_cache.back().key);
				m_LRU_cache.pop_back();
			}

			// insert in head.
			m_LRU_cache.push_front(newItem);
			m_map[key] = m_LRU_cache.begin();
			return;
		}

		m_map[key]->value = value;
		MoveToHead(key);
	}

private:
	unordered_map<int, list<CacheEntry>::iterator> m_map;
	list<CacheEntry> m_LRU_cache;
	int m_capacity;

	void MoveToHead(int key)
	{
		//Move key from current location to head
		auto updateEntry = *m_map[key];
		m_LRU_cache.erase(m_map[key]);
		m_LRU_cache.push_front(updateEntry);
		m_map[key] = m_LRU_cache.begin();
	}
};