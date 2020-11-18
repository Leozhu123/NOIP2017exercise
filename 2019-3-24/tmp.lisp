(defclass node ()
    ((ch
        :initarg :child
        :initform (list nil nil))
     (x 
        :initform 0)
     (delta
        :initform 0)))