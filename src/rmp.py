import os
import re

def remove_c_comments(text):
    # Regex pattern để match chuỗi ký tự, ký tự đơn và các loại chú thích
    # Giữ lại string literals để tránh xóa nhầm các dấu // hoặc /* nằm trong chuỗi "..."
    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\'])*\'|"(?:\\.|[^"\\])*"',
        re.DOTALL | re.MULTILINE
    )
    
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return ""  # Xóa chú thích
        else:
            return s   # Giữ nguyên chuỗi ký tự hoặc ký tự đơn
            
    return pattern.sub(replacer, text)

def process_directory(directory_path):
    for root, dirs, files in os.walk(directory_path):
        for file in files:
            if file.endswith(('.c', '.h')):
                file_path = os.path.join(root, file)
                try:
                    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                        content = f.read()
                    
                    cleaned_content = remove_c_comments(content)
                    
                    with open(file_path, 'w', encoding='utf-8') as f:
                        f.write(cleaned_content)
                        
                    print(f"Đã xử lý xong: {file_path}")
                except Exception as e:
                    print(f"Lỗi khi xử lý file {file_path}: {e}")

if __name__ == "__main__":
    target_dir = input("Nhập đường dẫn thư mục chứa mã nguồn C (để trống nếu là thư mục hiện tại): ").strip()
    if not target_dir:
        target_dir = "."
    process_directory(target_dir)
    print("Hoàn tất quá trình xóa chú thích!")