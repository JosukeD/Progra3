

namespace utec {
    template<typename T>
    struct Node {
        T data;
        std::unique_ptr<Node<T>> next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    template<typename T>
    class single_linked_list {
    private:
        std::unique_ptr<Node<T>> head_;

    public:
        single_linked_list() : head_(nullptr) {}

        single_linked_list(std::initializer_list<T> values) : single_linked_list() {
            for (auto it = values.begin(); it != values.end(); ++it) {
                push_front(*it);
            }
        }

        single_linked_list(const single_linked_list& other) : single_linked_list() {
            auto current = other.head_.get();
            while (current) {
                push_front(current->data);
                current = current->next.get();
            }
            reverse();
        }

        single_linked_list(single_linked_list&& other) noexcept : head_(std::move(other.head_)) {
            other.head_ = nullptr;
        }

        single_linked_list& operator=(const single_linked_list& other) {
            if (this != &other) {
                single_linked_list temp(other);
                head_ = std::move(temp.head_);
            }
            return *this;
        }

        // Move assignment operator
        single_linked_list& operator=(single_linked_list&& other) noexcept {
            if (this != &other) {
                head_ = std::move(other.head_);
                other.head_ = nullptr;
            }
            return *this;
        }

        void push_front(const T& value) {
            auto new_node = std::make_unique<Node<T>>(value);
            new_node->next = std::move(head_);
            head_ = std::move(new_node);
        }

        void pop_front() {
            if (head_) {
                head_ = std::move(head_->next);
            }
        }

        template<typename... Args>
        void emplace_front(Args&&... args) {
            auto new_node = std::make_unique<Node<T>>(std::forward<Args>(args)...);
            new_node->next = std::move(head_);
            head_ = std::move(new_node);
        }

        void reverse() {
            std::unique_ptr<Node<T>> prev = nullptr;
            auto current = std::move(head_);
            while (current) {
                auto next = std::move(current->next);
                current->next = std::move(prev);
                prev = std::move(current);
                current = std::move(next);
            }
            head_ = std::move(prev);
        }

        friend std::ostream& operator<<(std::ostream& os, const single_linked_list& list) {
            auto current = list.head_.get();
            while (current) {
                os << current->data << " ";
                current = current->next.get();
            }
            return os;
        }

        class iterator {
        private:
            Node<T>* current_;

        public:
            explicit iterator(Node<T>* node) : current_(node) {}

            iterator& operator++() {
                if (current_) {
                    current_ = current_->next.get();
                }
                return *this;
            }

            T& operator*() const {
                return current_->data;
            }

            bool operator!=(const iterator& other) const {
                return current_ != other.current_;
            }
        };

        iterator begin() const {
            return iterator(head_.get());
        }

        iterator end() const {
            return iterator(nullptr);
        }
    };
}
